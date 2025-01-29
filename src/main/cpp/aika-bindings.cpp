#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <vector>
#include <iostream>
#include <libaika.h>
#include <memory>


// ----------------
// Python interface
// ----------------

namespace py = pybind11;


class AikaBinding {
private:
        graal_isolate_t *isolate = NULL;
        graal_isolatethread_t *thread = NULL;

public:
    AikaBinding() {
        if (graal_create_isolate(NULL, &isolate, &thread) != 0) {
            std::cerr << "initialization error" << std::endl;
        }

       ::init(thread);
    }

    void destroy() {
        graal_tear_down_isolate(thread);
    }

    const char* greet(char* input) {
        // Call the function
        const char* result = ::greet(thread, input);

        // Duplicate the string to ensure the memory is managed independently
        size_t len = strlen(result);
        char* duplicated_result = new char[len + 1];
        strncpy(duplicated_result, result, len);
        duplicated_result[len] = '\0';  // Ensure null termination

        return duplicated_result;
    }

    void print() const {
        std::cout << "Hello from AikaBinding!" << std::endl;
    }
};

std::unique_ptr<AikaBinding> create_instance() {
    return std::make_unique<AikaBinding>();
}

PYBIND11_MODULE(aika_bindings,m)
{
  m.doc() = "pybind11 aika_bindings plugin";

  py::class_<AikaBinding>(m, "AikaBinding")
      .def(py::init<>())
      .def("destroy", &AikaBinding::destroy)
      .def("greet", &AikaBinding::greet)
      .def("print", &AikaBinding::print);

  m.def("create_instance", &create_instance, "Create a new AikaBinding instance");

}