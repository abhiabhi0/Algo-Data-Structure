def get_input():
    """
    get input from user
    """
    input_str = input("Enter elements to be sorted: ")
    try:
        elements = [int(e) for e in input_str.split()] #make a list of integers from input string
    except ValueError:
        print("Please enter a list of integers only, seperated by a space!!")
    return elements

def merge(thelist, start_idx: int, mid_idx: int, last_idx: int):
    """
    Merge two lists to form a single sorted list
    """
    size_left = mid_idx - start_idx + 1 #size of left list
    size_right = last_idx - mid_idx     #size of right list

    left_lst = []
    right_lst = []

    for i in range(size_left): #appending elements in left list
        left_lst.append(thelist[start_idx + i])

    for j in range(size_right): #appending elements in right list
        right_lst.append(thelist[mid_idx + 1 + j])

    left_idx = 0
    right_idx = 0
    curr_idx = start_idx

    #left index should be less than size of left list
    #right index should be less than size of right list
    while left_idx < size_left and right_idx < size_right:

        if left_lst[left_idx] <= right_lst[right_idx]: #comparing first elements of left list and right list
            thelist[curr_idx] = left_lst[left_idx]
            left_idx += 1 #increment

        else:
            thelist[curr_idx] = right_lst[right_idx]
            right_idx += 1 #increment

        curr_idx += 1 #increment

    #elemets in left list are not compared and all elements in right list are compared
    while left_idx < size_left:
        thelist[curr_idx] = left_lst[left_idx]
        curr_idx += 1 #increment
        left_idx += 1 #increment

    #elemets in right list are not compared and all elements in left list are compared
    while right_idx < size_right:
        thelist[curr_idx] = right_lst[right_idx]
        curr_idx += 1  #increment
        right_idx += 1 #increment

def merge_sort(thelist, start_idx: int, last_idx: int):
    """
    Merge Sort Algorithm
    """
    if len(thelist) == 0:
        print("Empty list!!")

    elif len(thelist) == 1:
        print("Only one element!!")

    elif start_idx < last_idx:
        mid_idx = (start_idx + last_idx) // 2 #middle element index
        merge_sort(thelist, start_idx, mid_idx)
        merge_sort(thelist, mid_idx + 1, last_idx)
        merge(thelist, start_idx, mid_idx, last_idx)

if __name__ == '__main__':
    input_list = get_input()
    merge_sort(input_list, 0, len(input_list) - 1)
    print(*input_list, sep = ", ")
