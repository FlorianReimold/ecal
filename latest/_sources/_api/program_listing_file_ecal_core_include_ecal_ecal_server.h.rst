
.. _program_listing_file_ecal_core_include_ecal_ecal_server.h:

Program Listing for File ecal_server.h
======================================

|exhale_lsh| :ref:`Return to documentation for file <file_ecal_core_include_ecal_ecal_server.h>` (``ecal/core/include/ecal/ecal_server.h``)

.. |exhale_lsh| unicode:: U+021B0 .. UPWARDS ARROW WITH TIP LEFTWARDS

.. code-block:: cpp

   /* ========================= eCAL LICENSE =================================
    *
    * Copyright (C) 2016 - 2024 Continental Corporation
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
   
   #pragma once
   
   #include <ecal/ecal_deprecate.h>
   #include <ecal/ecal_os.h>
   
   #include <ecal/ecal_callback.h>
   #include <ecal/ecal_service_info.h>
   #include <ecal/ecal_types.h>
   
   #include <memory>
   #include <string>
   
   namespace eCAL
   {
     class CServiceServerImpl;
   
     inline namespace v6
     {
       class ECAL_API_CLASS CServiceServer
       {
       public:
         ECAL_API_EXPORTED_MEMBER
           explicit CServiceServer(const std::string& service_name_, const ServerEventIDCallbackT event_callback_ = ServerEventIDCallbackT());
   
         ECAL_API_EXPORTED_MEMBER
           virtual ~CServiceServer();
   
         CServiceServer(const CServiceServer&) = delete;
   
         CServiceServer& operator=(const CServiceServer&) = delete;
   
         ECAL_API_EXPORTED_MEMBER
           CServiceServer(CServiceServer&& rhs) noexcept;
   
         ECAL_API_EXPORTED_MEMBER
           CServiceServer& operator=(CServiceServer&& rhs) noexcept;
   
         // TODO: Provide new MethodCallbackT type using SServiceMethodInformation instead "MethodCallbackT = std::function<int(const std::string& method_, const std::string& req_type_, const std::string& resp_type_, const std::string& request_, std::string& response_)>"
   
         ECAL_API_EXPORTED_MEMBER
           bool SetMethodCallback(const std::string& method_, const SServiceMethodInformation& method_info_, const MethodCallbackT& callback_);
   
         ECAL_API_EXPORTED_MEMBER
           bool RemoveMethodCallback(const std::string& method_);
   
         ECAL_API_EXPORTED_MEMBER
           std::string GetServiceName();
   
         // TODO: Implement this
   
         ECAL_API_EXPORTED_MEMBER
           Registration::SServiceMethodId GetServiceId() const;
   
         ECAL_API_EXPORTED_MEMBER
           bool IsConnected();
   
       private:
         std::shared_ptr<CServiceServerImpl> m_service_server_impl;
       };
     }
   } 
