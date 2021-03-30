class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        MyList = nums1 + nums2
        MyList.sort()
        print(MyList)
        l = len(MyList)
        if l % 2 == 1:
            return float(MyList[l//2])
        else:
            return float((MyList[l//2] + MyList[l//2-1])/2)