// Minimal template file for wrapping C++ code.

{include_boost}

#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>
#include <pybind11/pybind11.h>
#include <pybind11/operators.h>

#include <boost/optional.hpp>

{includes}
#include <boost/serialization/export.hpp>

{boost_class_export}

{holder_type}

// Preamble for STL classes
#include "python/{module_name}/preamble/{module_name}.h"

using namespace std;

namespace py = pybind11;

PYBIND11_MODULE({module_name}, m_) {{
    m_.doc() = "pybind11 wrapper of {module_name}";

    {wrapped_namespace}

// Specializations for STL classes
#include "python/{module_name}/specializations/{module_name}.h"

}}
