# Error handling
## Image size exceeds requested size
`ERROR : Image size (0xfffddbc) + trailer (0x20) exceeds requested size 0x100000`

This error usually happens when the hex file being signed contains multiple segments located far apart in memory space. For example, there are two applications in the hex file. The start address and size of the first one are 0x10002000 and 0x10000, and the start address and size of the second one are 0x20002000 and 0x10000. While signing the image, we specify the slot size 0x200000. However, the actual size of the slot will be 0x10010000, which is outside of the specified slot size.
### Solution 1
Increase the value of the `--slot-size` argument to match the entire image size.
### Solution 2
A potential solution for this issue is using multiple images for each application. Split the image into two images.
```bash
# Extract the application located at 0x10002000
$ edgeprotecttools hex-segment --image merged.hex --addr 0x10002000 --output app1.hex
# Extract the application located at 0x20002000
$ edgeprotecttools hex-segment --image merged.hex --addr 0x20002000 --output app2.hex
```
Then sign each application separately.
```bash
$ edgeprotecttools sign-image --image app1.hex --output app1_signed.hex --key private.pem
$ edgeprotecttools sign-image --image app2.hex --output app2_signed.hex --key private.pem
```
Now program the applications separately, or merge them into a single file.
```bash
$ edgeprotecttools merge-hex --image app1_signed.hex --image app2_signed.hex --output merged.hex
```
