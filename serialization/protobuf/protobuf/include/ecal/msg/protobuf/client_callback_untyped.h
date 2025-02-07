﻿/* ========================= eCAL LICENSE =================================
 *
 * Copyright (C) 2016 - 2025 Continental Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ========================= eCAL LICENSE =================================
*/

/**
 * @file   client_callback_untyped.h
**/

#pragma once

#include <ecal/msg/protobuf/client_callback_base.h>
#include <google/protobuf/message.h>
#include <string>

namespace eCAL
{
  namespace protobuf
  {
    /**
     * @brief Client class for untyped callback calls.
     *
     * Provides only the untemplated CallWithCallback method.
     */
    template <typename T>
    class CServiceClientUntypedCallback : public CServiceClientCallbackBase<T>
    {
    public:
      using CServiceClientCallbackBase<T>::CServiceClientCallbackBase; // Inherit constructors

      bool CallWithCallback(const std::string& method_name,
                            const google::protobuf::Message& request,
                            const ResponseCallbackT& response_callback,
                            int timeout = DEFAULT_TIME_ARGUMENT) const
      {
        bool overall_success = true;
        for (auto& instance : this->GetClientInstances())
        {
          overall_success &= instance.CallWithCallback(method_name, request, response_callback, timeout);
        }
        return overall_success;
      }
    };
  }
}
