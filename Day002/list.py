from typing import List, Optional

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

# 输入一个数组，转换为一条单链表
def createLinkedList(arr: 'List[int]') -> 'ListNode':
    if arr is None or len(arr) == 0:
        return None

    head = ListNode(arr[0])
    cur = head
    for i in range(1, len(arr)):
        cur.next = ListNode(arr[i])
        cur = cur.next

    return head

class DoublyListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
        self.prev = None
        
def createDoublyLinkedList(arr: List[int]) -> Optional[DoublyListNode]:
    if not arr:
        return None
    
    head = DoublyListNode(arr[0])
    cur = head
    
    # for 循环迭代创建双链表
    for val in arr[1:]:
        new_node = DoublyListNode(val)
        cur.next = new_node
        new_node.prev = cur
        cur = cur.next
    
    return head


if __name__ == "__main__":
    # 示例数组
    arr = [1, 2, 3, 4, 5]

    # 创建单链表
    single_linked_list = createLinkedList(arr)

    # 创建双链表
    doubly_linked_list = createDoublyLinkedList(arr)

    # 输出单链表中的元素
    print("单链表:")
    cur = single_linked_list
    while cur:
        print(cur.val, end=" -> ")
        cur = cur.next
    print("None")

    # 输出双链表中的元素
    print("\n双链表:")
    cur = doubly_linked_list
    while cur:
        print(f"({cur.prev.val if cur.prev else 'None'} <- {cur.val} -> {cur.next.val if cur.next else 'None'})")
        cur = cur.next
