import unittest
import gmTools as tls

class Test_uint_test(unittest.TestCase):
    #def test_read_ticks(self):
    #    tick_file_path='e:/data/ticks-000001-20180201.dat'
    #    ticks=tls.read_ticks(tick_file_path)
    #    print(ticks[:3])
    #    print(ticks[-3:])
        
        #self.fail("Not implemented")


    def test_read_cap(self):
       
        file_path='e:/data/CAP-000554-015.dat'
        data=tls.read_cap_flow(file_path)
        print(data[:3])
        print(data[-3:])

        ma=[5,10,20]
        nLastWeek=3
        nCount=sum(ma)+nLastWeek*2 
        i=max(len(data)-100,0)

        while i<len(data):
            if(tls.IsMaUp(data[i:i+nCount],ma,nLastWeek)):
                print ('main flow ma up',data[i+nCount-1:i+nCount])
            i=i+1

        

    #def test_get_code_in_cap_file(self):
    #    files=[]
    #    file_path='e:/data'
    #    files=tls.get_code_in_cap_file(file_path,'CAP','015',True)
    #    print(files[:3])
    #    print(files[-3:])
        

if __name__ == '__main__':
    unittest.main()
