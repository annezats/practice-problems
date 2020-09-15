import unittest

def question1(a,b):
    if len(a)!=len(b):
        return False

    sorta= sorted(a)
    sortb= sorted(b)

    for i in range(0,len(sorta)):
        if sorta[i] != sortb[i]:
            return False
    return True

def question2(numbers,target):
    results=[]
    while numbers!=[]:
        foo=False
        number=numbers[0]
        if number>target:
            numbers.remove(number)
            continue
        complement= target-number
        for number2 in numbers[1:]:
            if number2== complement:
                foo = True
        if foo:
            results.append([number,complement])
            numbers.remove(number)
            numbers.remove(complement)
        else:
            numbers.remove(number)
    return results



class TestMyStuff(unittest.TestCase):
    def test_first(self):
        self.assertTrue(question1("cd","dc"))
        self.assertTrue(question1("ccd","dcc"))
        self.assertFalse(question1("cdd","dcc")) #not permutation
        self.assertFalse(question1("c","dcc")) #different lengths
    def test_second(self):
        self.assertEqual(question2([1,2,5],3),[[1,2]])
        self.assertEqual(question2([1,5,3,2,4],6),[[1,5],[2,4]])
        self.assertEqual(question2([8],8),[])
    def test_third(self):
        self.assertEqual(question2([1, 1, 2, 2, 2],3),[[1,2],[1,2]])
if __name__ == "__main__":
    unittest.main()
