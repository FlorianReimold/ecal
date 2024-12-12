#pragma once

#include <string>
#include <iomanip>
#include <sstream>

#include <hdf5.h>

#include <ecalhdf5/eh5_types.h>

bool CreateStringEntryInRoot(hid_t root, const std::string& url, const std::string& dataset_content);
bool ReadStringEntryAsString(hid_t root, const std::string& url, std::string& data);

bool CreateBinaryEntryInRoot(hid_t root, const std::string& url, const std::string& dataset_content);
bool ReadBinaryEntryAsString(hid_t root, const std::string& url, std::string& data);

bool CreateInformationEntryInRoot(hid_t root, const std::string& url, const eCAL::eh5::EntryInfoVect& entries);
bool GetEntryInfoVector(hid_t root, const std::string& url, eCAL::eh5::EntryInfoSet& entries);

/**
* @brief Set attribute to object(file, entry...)
*
* @param id       ID of the attributes parent
* @param name     Name of the attribute
* @param value    Value of the attribute
*
* @return         true if succeeds, false if it fails
**/
bool SetAttribute(hid_t id, const std::string& name, const std::string& value);
/**
* @brief Gets the value of a string attribute
*
* @param [in]  obj_id ID of the attribute's parent
* @param [in]  name   Name of the attribute
* @param [out] value  Value of the attribute
*
* @return  true if succeeds, false if it fails
**/
bool GetAttribute(hid_t id, const std::string& name, std::string& value);

bool HasGroup(hid_t root, const std::string& path);

hid_t OpenOrCreateGroup(hid_t root, const std::string& name);

std::vector<std::string> ListSubgroups(hid_t id);


inline std::string printHex(eCAL::experimental::measurement::base::Channel::id_t id)
{
  std::stringstream ss;
  ss << std::hex << std::setw(16) << std::setfill('0') << std::uppercase << id;
  return ss.str();
}

inline eCAL::experimental::measurement::base::Channel::id_t parseHexID(std::string string_id)
{
  auto unsigned_value = std::stoull(string_id, 0, 16);
  return static_cast<eCAL::experimental::measurement::base::Channel::id_t>(unsigned_value);
}

namespace v6
{
  inline std::string GetUrl(const std::string& channel_name_, const std::string& channel_id, const std::string& attribute)
  {
    return "/" + channel_name_ + "/" + channel_id + "/" + attribute;
    //return "/" + channel_name_ + "/" + attribute;
  }
}