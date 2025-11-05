# 넘파이 Numpy

'''
넘파이에서 제공하는 자료형 : 배열 ndarray

-> 같은 자료형 값들을 저장하는 자료구조 (리스트는 같은 자료형이 아니어도 저장 가능)
-> 다수의 요소를 연산하고 저장하기에 효율적
-> 리스트에서 사용할 수 없는 연산들을 제공
'''

import numpy as np

arr1 = np.array([1, 2, 3, 4, 5])  # 1차원 배열 생성
print(type(arr1))  # <class 'numpy.ndarray'>
print(arr1.ndim)  # 배열의 차원 수 출력 (1)
print(arr1.shape)  # 배열의 각 차원의 크기 출력 (5,)
print(arr1.dtype)  # 배열 요소의 자료형 출력 (int32 등)
print(arr1.size)    # 배열의 총 요소 개수 출력 (5)

arr2 = np.array([[1, 2, 3], [4, 5, 6]])  # 2차원 배열 생성
print(type(arr2))  # <class 'numpy.ndarray'>
print(arr2.ndim)  # 배열의 차원 수 출력 (2)
print(arr2.shape)  # 배열의 각 차원의 크기 출력 (2, 3)
print(arr2.dtype)  # 배열 요소의 자료형 출력 (int32 등)
print(arr2.size)    # 배열의 총 요소 개수 출력 (6)

arr3 = np.zeros((2, 3))  # 2x3 배열 생성, 모든 요소가 0
arr4 = np.ones((3, 4))   # 3x4 배열 생성, 모든 요소가 1
arr5 = np.ones(5, dtype=int)  # 1차원 배열 생성, 모든 요소가 1 (정수형)

arr6 = np.arange(0, 10, 2)  # 0부터 10까지 2 간격의 정수 배열 생성

arr7 = arr1.reshape((5, 1))  # arr1을 5x1 배열로 재구성
print(arr7) # [[1]
            #  [2]
            #  [3]
            #  [4]
            #  [5]]

arr8 = arr2.reshape(-1)  # arr2를 1차원 배열로 재구성
arr8 = arr2.flatten()  # arr2를 1차원 배열로 평탄화

arr9 = np.arange(20).reshape((4, 5))  # 0부터 19까지의 값을 가진 4x5 배열 생성
print(arr9)
'''
[[ 0  1  2  3  4]
 [ 5  6  7  8  9]
 [10 11 12 13 14]
 [15 16 17 18 19]]
'''
print(arr9[2, 3])  # 13 출력 (3번째 행, 4번째 열)
print(arr9[1:3, 2:4]) # [[7 8]
                      #  [12 13]] 출력 (1~2번째 행, 2~3번째 열)
print(arr9[:, 1])  # [ 1 6 11 16] 출력 (모든 행, 2번째 열)

# 넘파이 브로드캐스팅

arr10 = np.ones(12).reshape((3, 4))
print(arr10)
'''
[[1. 1. 1. 1.]
 [1. 1. 1. 1.]
 [1. 1. 1. 1.]]
'''
arr[0] = arr[0] * 5
print(arr10)
'''
[[5. 5. 5. 5.]
 [1. 1. 1. 1.]
 [1. 1. 1. 1.]]
'''

arr10 = arr10 * np.arange(4)
print(arr10)
'''
[[ 0.  5. 10. 15.]
 [ 0.  1.  2.  3.]
 [ 0.  1.  2.  3.]]
'''


import pandas as pd

# 수입지별 상세 출고 기록 데이터 (열: 수입지, 상품명, 출고량, 가격)
df = pd.read_csv("data/shipment_log.csv")
                                                        
# 수입지와 상품명을 공백을 두고 입력
target_origin, target_product = input().split()
total_value = 0

target = df.groupby(['수입지', '상품명'])
print(target)

total_value = target.
print(total_value)