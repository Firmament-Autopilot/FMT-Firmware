// Copyright 2017 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _FASTCDR_SERIALIZATION_HPP_
#define _FASTCDR_SERIALIZATION_HPP_

#include <gtest/gtest.h>
#include <ucdr/microcdr.h>

#include <fastcdr/Cdr.h>
#include <fastcdr/FastCdr.h>
#include <fastcdr/exceptions/Exception.h>

#define BUFFER_LENGTH 2014

class FastCDRSerialization : public ::testing::Test
{
public:

    void double_sequence_with_aligment_serialization()
    {
        using namespace eprosima::fastcdr;

        char buffer_fastcdr[BUFFER_LENGTH] = {0};

        ucdrBuffer reader_fastcdr;
        ucdr_init_buffer(&reader_fastcdr, reinterpret_cast<uint8_t *>(buffer_fastcdr), BUFFER_LENGTH);
        
        FastBuffer cdrbuffer(buffer_fastcdr, BUFFER_LENGTH);
        Cdr cdr_ser(cdrbuffer);

        // Serialize 2 bytes
        const uint8_t octet_array[2] = {0xAA, 0xAA};
        cdr_ser.serializeArray(octet_array, 2);

        uint8_t octet_array_out[2] = {};
        EXPECT_TRUE(ucdr_deserialize_array_uint8_t(&reader_fastcdr, octet_array_out, 2));
        EXPECT_EQ(octet_array[0], octet_array_out[0]);
        EXPECT_EQ(octet_array[1], octet_array_out[1]);

        // Serialize 2 doubles = 16 Bytes + 1 Header 
        const double double_seq[2] = {3.14, 3.14};
        cdr_ser.serializeSequence(double_seq, 2);
        
        double double_seq_out[2];
        uint32_t double_seq_len;
        EXPECT_TRUE(ucdr_deserialize_sequence_double(&reader_fastcdr, double_seq_out, 2, &double_seq_len));
        EXPECT_EQ(double_seq_len, 2u);

        // Serialize 0 doubles = 1 header
        std::vector<double> double_vector;
        cdr_ser.serializeSequence(double_seq, 0);

        EXPECT_TRUE(ucdr_deserialize_sequence_double(&reader_fastcdr, double_seq_out, 2, &double_seq_len));
        EXPECT_EQ(double_seq_len, 0u);

        // Serialize 2 bytes
        cdr_ser.serializeArray(octet_array, 2);

        EXPECT_TRUE(ucdr_deserialize_array_uint8_t(&reader_fastcdr, octet_array_out, 2));
        EXPECT_EQ(octet_array[0], octet_array_out[0]);
        EXPECT_EQ(octet_array[1], octet_array_out[1]);

    }
};

#endif //_FASTCDR_SERIALIZATION_HPP_
