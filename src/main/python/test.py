import aika_bindings

A = [1.,2.,3.,4.]

B = aika_bindings.modify(A)

print(B)

print(aika_bindings.call_graalvm("Blub"))

obj = aika_bindings.MyClass()

# Call methods on the object
obj.print()  # This will output: "Hello from MyClass!"





