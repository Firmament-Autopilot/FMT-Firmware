"""
Copyright 2025 Cypress Semiconductor Corporation (an Infineon company)
or an affiliate of Cypress Semiconductor Corporation. All rights reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
"""
import logging
import os.path

from intelhex import IntelHex

logger = logging.getLogger(__name__)

class HexRelocator:
    """
    Efficiently relocates address regions in an Intel HEX file from given
    start addresses to destination addresses.
    """

    @staticmethod
    def validate_regions(regions):
        """
        Validates regions and checks for destination intersections.
        :param regions: List of (start, size, dest) tuples.
        :raises ValueError: If validation fails.
        """
        if not isinstance(regions, (list, tuple)):
            raise TypeError(
                "regions must be a list or tuple of (start, size, dest) tuples"
            )
        dest_ranges = []
        for idx, region in enumerate(regions):
            if not (isinstance(region, (list, tuple)) and len(region) == 3):
                raise ValueError(
                    f"Region #{idx+1} must be a tuple/list of three integers: "
                    f"(start, size, dest)"
                )
            start, size, dest = region
            HexRelocator._validate_region(idx, start, size, dest)
            dest_ranges.append((dest, dest + size))
        HexRelocator._check_dest_intersections(dest_ranges)

    @staticmethod
    def _validate_region(idx, start, size, dest):
        """Helper to validate a single region tuple."""
        if not (isinstance(start, int) and isinstance(size, int)
                and isinstance(dest, int)):
            raise ValueError(
                f"Region #{idx+1} values must be integers: "
                f"(start, size, dest)"
            )
        if start < 0 or size <= 0 or dest < 0:
            raise ValueError(
                f"Region #{idx+1} has invalid values: "
                f"start and dest must be >= 0, size must be > 0"
            )
        if start > 0xFFFFFFFF or dest > 0xFFFFFFFF:
            raise ValueError(
                f"Region #{idx+1} start and dest must be <= 0xFFFFFFFF "
                f"(32-bit address space)"
            )
        if start + size > 0x100000000:
            raise ValueError(
                f"Region #{idx+1} start + size must not overflow "
                f"32-bit address space"
            )
        if dest + size > 0x100000000:
            raise ValueError(
                f"Region #{idx+1} dest + size must not overflow "
                f"32-bit address space"
            )

    @staticmethod
    def _check_dest_intersections(dest_ranges):
        """Check for intersections between destination regions."""
        for i, (start_i, end_i) in enumerate(dest_ranges):
            for j in range(i + 1, len(dest_ranges)):
                start_j, end_j = dest_ranges[j]
                if not (end_i <= start_j or start_i >= end_j):
                    raise ValueError(
                        f"Destination region #{i+1} (0x{start_i:08X}-0x{end_i:08X}) "
                        f"intersects with destination region #{j+1} "
                        f"(0x{start_j:08X}-0x{end_j:08X})"
                    )

    @staticmethod
    def load_hex_file(infile):
        """
        Loads an Intel HEX file.
        :param infile: Path to input HEX file.
        :return: IntelHex object or None if file is invalid.
        """
        ih = None
        if os.path.isfile(infile):
            try:
                ih = IntelHex(infile)
            except UnicodeDecodeError:
                logger.error("Input file '%s' is not a valid Intel HEX file",
                             infile)
        else:
            logger.error("Input file '%s' does not exist or is not a file",
                         infile)
        return ih

    @staticmethod
    def relocate_hex(ih, regions):
        """
        Relocate all relevant address data in an IntelHex object and
        return a new IntelHex object. Segments are relocated if they are
        fully within any region, otherwise copied unchanged.
        :param ih: IntelHex object to relocate.
        :param regions: List of (start, size, dest) tuples.
        :return: New IntelHex object with relocated data.
        """
        HexRelocator.validate_regions(regions)
        new_ih = IntelHex()
        for seg_start, seg_end in ih.segments():
            for start, size, dest in regions:
                region_start = start
                region_end = start + size
                if seg_start >= region_start and seg_end <= region_end:
                    new_start = seg_start - region_start + dest
                    new_end = seg_end - region_start + dest
                    logger.info(
                        "Relocating segment 0x%08X-0x%08X to 0x%08X-0x%08X",
                        seg_start, seg_end, new_start, new_end
                    )
                    new_ih.puts(
                        new_start,
                        bytes(ih.tobinarray(start=seg_start, end=seg_end - 1))
                    )
                    break
            else:
                logger.info(
                    "Copying segment 0x%08X-0x%08X unchanged",
                    seg_start, seg_end
                )
                new_ih.puts(
                    seg_start,
                    bytes(ih.tobinarray(start=seg_start, end=seg_end - 1))
                )
        return new_ih

    @staticmethod
    def relocate_file(infile, outfile, regions):
        """
        Load a HEX file, validate input data, relocate relevant address
        data, and write to output hex file.
        :param infile: Path to input HEX file.
        :param outfile: Path to output HEX file.
        :param regions: List of (start, size, dest) tuples.
        :return: New IntelHex object with relocated data.
        """
        new_ih = None
        ih = HexRelocator.load_hex_file(infile)
        if ih:
            HexRelocator.validate_regions(regions)
            new_ih = HexRelocator.relocate_hex(ih, regions)
            new_ih.write_hex_file(outfile)
        return new_ih
