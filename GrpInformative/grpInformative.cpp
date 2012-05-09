/*
 * Copyright (c) 2011, Intel Corporation.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#include "tnvme.h"
#include "../Exception/frmwkEx.h"
#include "grpInformative.h"
#include "dumpRegisters_r10b.h"
#include "createResources_r10b.h"
#include "dumpGetFeatures_r10b.h"
#include "dumpIdentifyData_r10b.h"
#include "compareGolden_r10b.h"

namespace GrpInformative {


GrpInformative::GrpInformative(size_t grpNum, SpecRev specRev,
    ErrorRegs errRegs, int fd) :
    Group(grpNum, specRev, "GrpInformative", "Informative")
{
    // ------------------------CHANGE NOTICE: (3-2-2012)------------------------
    // The rule to keep groups and tests at a well known constant reference
    // number for all of time is to restrictive. A new scheme has replaced
    // that strategy. For complete details refer to:
    // "https://github.com/nvmecompliance/tnvme/wiki/Test-Numbering" and
    // "https://github.com/nvmecompliance/tnvme/wiki/Test-Strategy
    switch (mSpecRev) {
    case SPECREV_10b:
        APPEND_TEST_AT_XLEVEL(DumpRegisters_r10b, fd, GrpInformative, errRegs)
        APPEND_TEST_AT_XLEVEL(CreateResources_r10b, fd, GrpInformative, errRegs)
        APPEND_TEST_AT_YLEVEL(DumpGetFeatures_r10b, fd, GrpInformative, errRegs)
        APPEND_TEST_AT_YLEVEL(DumpIdentifyData_r10b, fd, GrpInformative, errRegs)
        APPEND_TEST_AT_ZLEVEL(CompareGolden_r10b, fd, GrpInformative, errRegs)
        break;

    default:
    case SPECREVTYPE_FENCE:
        throw FrmwkEx(HERE, "Object created with unknown SpecRev=%d", specRev);
    }
}


GrpInformative::~GrpInformative()
{
    // mTests deallocated in parent
}

}   // namespace
