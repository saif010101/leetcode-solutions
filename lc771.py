class Solution(object):
    def numJewelsInStones(self, jewels, stones):
        """
        :type jewels: str
        :type stones: str
        :rtype: int
        """
        count = 0

        for i in range(len(stones)):
            if stones[i] in jewels:
                count = count + 1

        return count
