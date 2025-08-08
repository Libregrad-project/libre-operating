include ../config/config

echo "Hello, Nim on Windows 7!"

# In memory pointer.
var x = 42
var ptrX: ptr int = addr x
# Print the pointer. [] de-references it.
echo ptrX[]

# Global accessable variable.
var globalVariable = 50

proc printGlobal() =
    echo globalVariable

proc greet(name: cstring) =
    echo "Hello, ", name, "!"

proc runTest() =
  echo "OS Name: ", OS_NAME
  echo "Version: ", VERSION

runTest()

greet("Libre Operating")
printGlobal()