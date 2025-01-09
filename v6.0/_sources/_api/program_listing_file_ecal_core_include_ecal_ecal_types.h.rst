
.. _program_listing_file_ecal_core_include_ecal_ecal_types.h:

Program Listing for File ecal_types.h
=====================================

|exhale_lsh| :ref:`Return to documentation for file <file_ecal_core_include_ecal_ecal_types.h>` (``ecal/core/include/ecal/ecal_types.h``)

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
   #include <string>
   #include <tuple>
   #include <iostream>
   
   namespace eCAL
   {
     struct SVersion
     {
       const int major; 
       const int minor; 
       const int patch; 
     };
   
     struct SDataTypeInformation
     {
       std::string name;          
       std::string encoding;      
       std::string descriptor;    
   
       bool operator==(const SDataTypeInformation& other) const
       {
         return name == other.name && encoding == other.encoding && descriptor == other.descriptor;
       }
   
       bool operator!=(const SDataTypeInformation& other) const
       {
         return !(*this == other);
       }
   
       bool operator<(const SDataTypeInformation& rhs) const
       {
           return std::tie(name, encoding, descriptor) < std::tie(rhs.name, rhs.encoding, rhs.descriptor);
       }
   
       void clear()
       {
         name.clear();
         encoding.clear();
         descriptor.clear();
       }
     };
   
     struct SServiceMethodInformation
     {
       SDataTypeInformation request_type;   
       SDataTypeInformation response_type;  
   
       bool operator==(const SServiceMethodInformation& other) const
       {
         return request_type == other.request_type && response_type == other.response_type;
       }
   
       bool operator!=(const SServiceMethodInformation& other) const
       {
         return !(*this == other);
       }
   
       bool operator<(const SServiceMethodInformation& rhs) const
       {
         return std::tie(request_type, response_type) < std::tie(rhs.request_type, rhs.response_type);
       }
     };
   
     namespace Registration
     {
       struct SEntityId
       {
         std::string  entity_id;         // unique id within that process (it should already be unique within the whole system)
         int32_t      process_id = 0;    // process id which produced the sample
         std::string  host_name;         // host which produced the sample
   
         bool operator==(const SEntityId& other) const {
           return entity_id == other.entity_id;
         }
   
         bool operator<(const SEntityId& other) const
         {
           return entity_id < other.entity_id;
         }
       };
   
       // Overload the << operator for SEntityId
       inline std::ostream& operator<<(std::ostream& os, const SEntityId& id)
       {
         os << "SEntityId(entity_id: " << id.entity_id
           << ", process_id: " << id.process_id
           << ", host_name: " << id.host_name << ")";
         return os;
       }
   
       struct STopicId
       {
         SEntityId    topic_id;
         std::string  topic_name;
   
         bool operator==(const STopicId& other) const
         {
           return topic_id == other.topic_id && topic_name == other.topic_name;
         }
   
         bool operator<(const STopicId& other) const
         {
           return std::tie(topic_id, topic_name) < std::tie(other.topic_id, other.topic_name);
         }
       };
   
       inline std::ostream& operator<<(std::ostream& os, const STopicId& id)
       {
         os << "STopicId(topic_id: " << id.topic_id
           << ", topic_name: " << id.topic_name << ")";
         return os;
       }
   
       struct SServiceMethodId
       {
         SEntityId    service_id;
         std::string  service_name;
         std::string  method_name;
   
         bool operator==(const SServiceMethodId& other) const
         {
           return service_id == other.service_id && service_name == other.service_name && method_name == other.method_name;
         }
   
         bool operator<(const SServiceMethodId& other) const
         {
           return std::tie(service_id, service_name, method_name) < std::tie(other.service_id, other.service_name, other.method_name);
         }
       };
     }
   }
