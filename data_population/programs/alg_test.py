from ctypes import CDLL
lib = CDLL("./library.so")
result = lib.main("cat", "pat")
print(result)
