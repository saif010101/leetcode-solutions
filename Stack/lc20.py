# Python code for LC 20 : Valid Parentheses i wrote while learning python.

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # create an empty stack
        stk = []

        open_par = ['(','{','[']
        closed_par = [')','}',']']

        for i in range(len(s)):
            if s[i] in {'(','{','['}:
                stk.append(s[i])
            else:
                if len(stk) == 0:
                    return False
                elif open_par.index(stk[-1]) == closed_par.index(s[i]):
                    stk.pop()
                else:
                    return False
                
        

        return len(stk) == 0
                
        
