
.. _program_listing_file_ecal_core_include_ecal_ecal_callback.h:

Program Listing for File ecal_callback.h
========================================

|exhale_lsh| :ref:`Return to documentation for file <file_ecal_core_include_ecal_ecal_callback.h>` (``ecal/core/include/ecal/ecal_callback.h``)

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
   #include <ecal/cimpl/ecal_callback_cimpl.h>
   #include <ecal/ecal_types.h>
   
   #include <functional>
   #include <string>
   
   namespace eCAL
   {
     struct SReceiveCallbackData
     {
       void*     buf   = nullptr;  
       long      size  = 0;        
       long long id    = 0;        
       long long time  = 0;        
       long long clock = 0;        
     };
   
     struct SPubEventCallbackData
     {
       eCAL_Publisher_Event type{pub_event_none};  
       long long            time{0};               
       long long            clock{0};              
       std::string          tid;                   
       SDataTypeInformation tdatatype;             
     };
   
     struct SSubEventCallbackData
     {
       eCAL_Subscriber_Event type{sub_event_none}; 
       long long             time{0};              
       long long             clock{0};             
       std::string           tid;                  
       SDataTypeInformation  tdatatype;            
     };
   
     struct SServiceAttr
     {
       std::string    key;              
       std::string    hname;            
       std::string    pname;            
       std::string    uname;            
       std::string    sname;            
       std::string    sid;              
       int            pid         = 0;  
   
       // internal protocol specifics
       unsigned int   version     = 0;  
       unsigned short tcp_port_v0 = 0;  
       unsigned short tcp_port_v1 = 0;  
     };
   
     struct SClientEventCallbackData
     {
       eCAL_Client_Event type = client_event_none;  
       long long         time = 0;                  
       SServiceAttr      attr;                      
     };
   
     struct SClientAttr
     {
       std::string    key;           
       std::string    hname;         
       std::string    pname;         
       std::string    uname;         
       std::string    sname;         
       std::string    sid;           
       int            pid = 0;       
   
       unsigned int   version = 0;   
     };
   
     struct SServerEventCallbackData
     {
       eCAL_Server_Event type = server_event_none;  
       long long         time = 0;                  
     };
   
     using ReceiveCallbackT = std::function<void (const char* topic_name_, const struct SReceiveCallbackData* data_)>;
   
     using ReceiveIDCallbackT = std::function<void(const Registration::STopicId& topic_id_, const SDataTypeInformation& data_type_info_, const SReceiveCallbackData& data_)>;
   
     using TimerCallbackT = std::function<void ()>;
   
     using PubEventCallbackT = std::function<void (const char* topic_name_, const struct SPubEventCallbackData* data_)>;
   
     using PubEventIDCallbackT = std::function<void(const Registration::STopicId& topic_id_, const struct SPubEventCallbackData& data_)>;
   
     using SubEventCallbackT = std::function<void (const char* topic_name_, const struct SSubEventCallbackData* data_)>;
   
     using SubEventIDCallbackT = std::function<void(const Registration::STopicId& topic_id_, const struct SSubEventCallbackData& data_)>;
   
     using ClientEventCallbackT = std::function<void (const char* service_name_, const struct SClientEventCallbackData* data_)>;
   
     using ClientEventIDCallbackT = std::function<void(const Registration::SServiceMethodId& service_id_, const struct SClientEventCallbackData& data_)>;
   
     using ServerEventCallbackT = std::function<void (const char* service_name_, const struct SServerEventCallbackData* data_)>;
   
     using ServerEventIDCallbackT = std::function<void(const Registration::SServiceMethodId& service_id_, const struct SServerEventCallbackData& data_)>;
   }
