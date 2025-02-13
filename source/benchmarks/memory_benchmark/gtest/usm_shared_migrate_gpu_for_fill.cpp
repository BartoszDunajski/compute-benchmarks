/*
 * Copyright (C) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: MIT
 *
 */

#include "definitions/usm_shared_migrate_gpu_for_fill.h"

#include "framework/test_case/register_test_case.h"
#include "framework/utility/common_gtest_args.h"
#include "framework/utility/memory_constants.h"

#include <gtest/gtest.h>

static const inline RegisterTestCase<UsmSharedMigrateGpuForFill> registerTestCase{};

class UsmSharedMigrateGpuForFillTest : public ::testing::TestWithParam<std::tuple<Api, size_t, bool, bool>> {
};

TEST_P(UsmSharedMigrateGpuForFillTest, Test) {
    UsmSharedMigrateGpuForFillArguments args;
    args.api = std::get<0>(GetParam());
    args.bufferSize = std::get<1>(GetParam());
    args.prefetchMemory = std::get<2>(GetParam());
    args.forceBlitter = std::get<3>(GetParam());

    UsmSharedMigrateGpuForFill test;
    test.run(args);
}

using namespace MemoryConstants;
INSTANTIATE_TEST_SUITE_P(
    UsmSharedMigrateGpuForFillTest,
    UsmSharedMigrateGpuForFillTest,
    ::testing::Combine(
        ::CommonGtestArgs::allApis(),
        ::testing::Values(128 * megaByte, 256 * megaByte),
        ::testing::Values(false, true),
        ::testing::Values(false, true)));
