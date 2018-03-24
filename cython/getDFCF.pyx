from libc.math cimport sin
def addtest(a,b):
    cdef float c=a+b
    return c

#def f(double x):
#    cdef double ret
#    ret=x**2-x
#    return ret

cdef double f(double x):
    return sin(x*x)