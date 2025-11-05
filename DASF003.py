


#Lecture 09 : Immutable Data Types in Python

# Tuple

t1 = (1, 2, 3, 4, 5)
t2 = 1, 2, 3, 4, 5

"""
t1.append(5) => 같은 접근은 불가능하다.
tuple은 immutable(변경 불가능) 자료형이다.

number, string, boolean, tuple은 모두 immutable 자료형이다.
number나 string, boolean, tuple은 값을 변경하는 것이 아니라 새로운 값을 생성하는 방식으로 동작.

list, set, dictionary는 mutable(변경 가능) 자료형이다.

"""

list_a = [1, 2, 3]
list_b = list(list_a)  # list_a의 복사본 list_b 생성
list_b.append(4)  # list_b에 4 추가 -> list_a에는 영향 없음

# String

string_a = "abcdefgh"

"""
String은 character의 시퀀스로 이루어진 immutable 자료형이다.
string_a[0] = "z" => 같은 접근은 불가능하다.

string은 [s:e] slicing을 통해 substring을 추출할 수 있다.
list, tuple, string 모두 시퀀스 자료형이므로 공통적으로 indexing과 slicing이 가능하다.

"""

string_a[1:5]  # 'bcde' 반환
string_a[5:]   # 'fgh' 반환
string_a[:3]   # 'abc' 반환
string_a[:]    # 'abcdefgh' 반환
string_a[-3:]  # 'fgh' 반환
string_a[:-3]  # 'abcde' 반환
string_a[::2]  # 'aceg' 반환
string_a[::-1] # 'hgfedcba' 반환 (역순)

"""
in 연산자를 사용하여 substring 존재 여부 확인 가능.

list, tuple, string 모두 시퀀스 자료형이므로 공통적으로 in 연산자 사용 가능.

"""

country = ['Korea', 'USA', 'China', 'Japan']

print('USA' in country)        # True
print('Germany' in country)    # False

text = " Hello, world! "
print('world' in text)         # True
print('Python' in text)        # False

# String Methods

"""
    String Methods

    - lower(): 모든 문자를 소문자로 변환
    - upper(): 모든 문자를 대문자로 변환
    - strip(): 문자열 양쪽의 공백 제거

    - isalpha(): 문자열이 알파벳 문자로만 구성되어 있는지 확인
    - isdigit(): 문자열이 숫자로만 구성되어 있는지 확인
    - isspace(): 문자열이 공백 문자로만 구성되어 있는지 확인
    - isalnum(): 문자열이 알파벳 문자와 숫자로만 구성되어 있는지 확인

    - startswith(prefix): 문자열이 특정 접두사로 시작하는지 확인
    - endswith(suffix): 문자열이 특정 접미사로 끝나는지 확인

    - find(substring): substring이 처음 나타나는 위치의 index 반환 (없으면 -1 반환)
    - replace(old, new): 문자열 내의 old substring을 new substring으로 대체

    - split(separator): 문자열을 separator 기준으로 분리하여 list로 반환
    - join(list): list의 문자열 element들을 하나의 문자열로 결합
"""

# Set -> unordered collection of unique elements

set_a = set()
set_b = {1, 2, 3, 4, 5}

set_a.add(1)
set_b.remove(1)
set_b.discard(2)  # remove와 유사하지만, element가 없어도 에러 발생하지 않음
set_a.update({2, 3, 4})  # 여러 element 추가

print(set_a) # {1, 2, 3, 4}가 출력된다.

set_c = {1, 2, 3, 4, 5}
set_d = {4, 5, 6, 7, 8}

set_c & set_d  # 교집합 {4, 5}
set_c.intersection(set_d)  # 교집합 {4, 5}
set_c | set_d  # 합집합 {1, 2, 3, 4, 5, 6, 7, 8}
set_c.union(set_d)  # 합집합 {1, 2, 3, 4, 5, 6, 7, 8}
set_c - set_d  # 차집합 {1, 2, 3}
set_c.difference(set_d)  # 차집합 {1, 2, 3}

"""
set은 중복된 값을 허용하지 않는 자료형이다.
set은 list, tuple, string 등을 인자로 받아서 중복을 제거한 후 set으로 변환할 수 있다.

set('google') => {'g', 'o', 'l', 'e'} 반환
set([1, 2, 2, 3, 4, 4, 5]) => {1, 2, 3, 4, 5} 반환
set((1, 1, 2, 3, 3, 4, 5)) => {1, 2, 3, 4, 5} 반환

"""

fruits_set = {'apple', 'banana', 'orange'}
# in 연산자를 사용하여 set 내의 요소 존재 여부 확인 가능
for fruit in ["mango", "apple"]:
    if fruit in fruits_set:
        print(f"{fruit} is in the set.")
    else:
        print(f"{fruit} is not in the set.")

