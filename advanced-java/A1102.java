import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.stream.Collectors;

public class A1102 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = Integer.parseInt(scan.nextLine());

		boolean[] hash = new boolean[n];
		TreeNode[] tree = new TreeNode[n];

		// 构建二叉树
		for (int i = 0; i < n; i++) {
			String[] sArr = scan.nextLine().split(" ");
			if (tree[i] == null) {
				tree[i] = new TreeNode(i);
			}
			if (!"-".equals(sArr[0])) {
				int index = Integer.parseInt(sArr[0]);
				if (tree[index] == null) {
					tree[index] = new TreeNode(index);
				}
				hash[index] = true;
				tree[i].left = tree[index];
			}
			if (!"-".equals(sArr[1])) {
				int index = Integer.parseInt(sArr[1]);
				if (tree[index] == null) {
					tree[index] = new TreeNode(index);
				}
				hash[index] = true;
				tree[i].right = tree[index];
			}
		}
		scan.close();

		int idx = 0;
		for (int i = 0; i < hash.length; i++) {
			if (!hash[i]) {
				idx = i;
				break;
			}
		}

		TreeNode root = tree[idx];

		// 反转二叉树
		invert(root);

		// 层次遍历
		List<Integer> levelList = new ArrayList<>();
		levelOrder(root, levelList);
		System.out.println(levelList.stream().map(String::valueOf).collect(Collectors.joining(" ")));

		// 中序遍历
		List<Integer> inList = new ArrayList<>();
		inOrder(root, inList);
		System.out.println(inList.stream().map(String::valueOf).collect(Collectors.joining(" ")));
	}

	private static void invert(TreeNode root) {
		if (root == null) {
			return;
		}
		invert(root.left);
		invert(root.right);

		TreeNode node = root.right;
		root.right = root.left;
		root.left = node;
	}

	private static void levelOrder(TreeNode root, List<Integer> list) {
		if (root == null) {
			return;
		}
		Queue<TreeNode> queue = new LinkedList<>();
		queue.offer(root);

		while (!queue.isEmpty()) {
			int size = queue.size();
			for (int i = 0; i < size; i++) {
				TreeNode node = queue.poll();
				list.add(node.index);
				if (node.left != null) {
					queue.offer(node.left);
				}
				if (node.right != null) {
					queue.offer(node.right);
				}
			}
		}
	}

	private static void inOrder(TreeNode root, List<Integer> list) {
		if (root == null) {
			return;
		}
		inOrder(root.left, list);
		list.add(root.index);
		inOrder(root.right, list);
	}

	static class TreeNode {
		int index;
		TreeNode left, right;

		public TreeNode(int index) {
			super();
			this.index = index;
		}

		@Override
		public String toString() {
			return "TreeNode [index=" + index + ", left=" + left + ", right=" + right + "]";
		}

	}
}
