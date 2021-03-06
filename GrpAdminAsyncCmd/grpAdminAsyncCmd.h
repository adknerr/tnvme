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

#ifndef _GRPADMINASYNCCMD_H_
#define _GRPADMINASYNCCMD_H_

#include "../group.h"

namespace GrpAdminAsyncCmd {


/**
* This class implements admin cmd set async event request test cases.
*/
class GrpAdminAsyncCmd : public Group
{
public:
    GrpAdminAsyncCmd(size_t grpNum);
    virtual ~GrpAdminAsyncCmd();
};

}   // namespace

#endif
