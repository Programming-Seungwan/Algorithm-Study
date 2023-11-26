#전위 순회: 자기 자신 처리->왼쪽 자식노드 방문->오른쪽 자식노드 방문
def preorder(node):
    if node is not None:
        #현재 노드 방문(출력과 같은 작업 수행)
        print(node.value)
        preorder(node.left)  #왼쪽 자식노드 순회
        preorder(node.right)  #오른쪽 자식노드 순회 


#중위 순회: 왼쪽 자식노드 방문->자기 자신 처리->오른쪽 자식드로 이동
def inorder(node):
    if node is not None:
        #왼쪽 서브트리 순회
        inorder(node.left)
        print(node.value) #현재 노드 처리
        inorder(node.right)   #오른쪽 자식노드 방문


#후위 순회: 왼쪽 서브트리->오른쪽 서브트리->현재 노드 출력
def postorder(node):
    if node is not None:
        postorder(node.left)
        postorder(node.right)
        print(node.value)



#트리 생성(클래스로 구현)하여 전위 순회,후위 순회,중위 순회의 결과 출력해보기
class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

# 예시 트리 생성
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)
root.right.left = TreeNode(6)
root.right.right = TreeNode(7)

# 전위 순회: 1,2,4,5,3,6,7
preorder(root)

# 중위 순회: 4,2,5,1,6,3,7
inorder(root)

# 후위 순회: 4,5,2,6,7,3,1
postorder(root)