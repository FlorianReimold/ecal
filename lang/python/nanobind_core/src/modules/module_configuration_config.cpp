/* ========================= eCAL LICENSE =================================
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
 * @brief  Add Configuration config structs to nanobind module
**/


#include <modules/module_configuration_config.h>
#include <ecal/config/configuration.h>

namespace nb = nanobind;

void AddConfigurationConfigStructToModule(nanobind::module_& m)
{
    nb::class_<eCAL::Configuration>(m, "Configuration")
        // Constructors
        .def(nb::init<>())  // Default constructor
  //      .def(nb::init<int, char**>(), nb::arg("argc_"), nb::arg("argv_"))
  //      .def(nb::init<const std::vector<std::string>&>(), nb::arg("args_"))

        // Methods
        .def("InitFromConfig", &eCAL::Configuration::InitFromConfig, "Initialize configuration from default settings")
        .def("InitFromFile", &eCAL::Configuration::InitFromFile, nb::arg("yaml_path_"), "Initialize configuration from a YAML file")
        .def("GetYamlFilePath", &eCAL::Configuration::GetYamlFilePath, "Get the YAML configuration file path")

        // Public members
        .def_rw("transport_layer", &eCAL::Configuration::transport_layer)
        .def_rw("registration", &eCAL::Configuration::registration)
        .def_rw("monitoring", &eCAL::Configuration::monitoring)
        .def_rw("subscriber", &eCAL::Configuration::subscriber)
        .def_rw("publisher", &eCAL::Configuration::publisher)
        .def_rw("timesync", &eCAL::Configuration::timesync)
        .def_rw("service", &eCAL::Configuration::service)
        .def_rw("application", &eCAL::Configuration::application)
        .def_rw("logging", &eCAL::Configuration::logging)
        .def_rw("command_line_arguments", &eCAL::Configuration::command_line_arguments);
}

