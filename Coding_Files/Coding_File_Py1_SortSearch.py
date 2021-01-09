import random
list1 = []
count = 1

list1.append(random.randint(1, 100))

while(True):
    num = random.randint(1, 100)
    flag = 1
    for i in range(len(list1)):
        if (num == list1[i]):
            flag = 0
            break
    if (flag):
        list1.append(num)
        count += 1

    if (count >= 10):
        break

print("초기 리스트:", list1)

for i in range(0, 10, 1):
    min = i
    for j in range(i+1, 10, 1):
        if list1[j] < list1[min]:
            min = j
    temp = list1[i]
    list1[i] = list1[min]
    list1[min] = temp
    print("%d번째 선택정렬 후:"%(i+1), list1)

print("정렬 결과:", list1)
print("")

key = int(input("탐색하고자하는 숫자: "))

def search(key):
    flag = 0
    low = 0
    high = 9

    for i in range(0, 10, 1):
        if low <= high:
            mid = int((low+high)/2)

            if key == list1[mid]:
                flag = 1
                break
            elif key < list1[mid]:
                high = mid - 1
            else:
                low = mid + 1

    if (flag == 1):
        print("탐색에 성공하였습니다.", key, "의 index는", mid,"번 입니다.")
        return flag
    else:
        print("탐색에 실패하였습니다. 다시 입력하세요.\n",)
        return flag

while(True):
    result = search(key)
    if(result):
        break
    else:
        key = int(input("탐색하고자하는 숫자: "))


          
