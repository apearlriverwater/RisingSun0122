import unittest
import read_bin_file as rbf

class Test_uint_test(unittest.TestCase):
    def test_A(self):
        ticks=[]
        tick_file_path='e:/data/ticks-000001-20180201.dat'
        rbf.read_ticks(tick_file_path,ticks)
        print(ticks[:3])
        print(ticks[-3:])
        
        self.fail("Not implemented")

if __name__ == '__main__':
    unittest.main()
