import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

/**
 * 1150 Travelling Salesman Problem (25分) 最后一个测试用例超时
 * 
 * @author hegongshan
 * @date 2020/09/04
 */
public class A1150 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		int m = scan.nextInt();

		int[][] graph = new int[n + 1][n + 1];
		for (int i = 0; i < m; i++) {
			int u = scan.nextInt();
			int v = scan.nextInt();
			int w = scan.nextInt();
			graph[u][v] = graph[v][u] = w;
		}

		int shortestDist = Integer.MAX_VALUE;
		int idx = -1;

		int k = scan.nextInt();
		for (int i = 1; i <= k; i++) {
			int num = scan.nextInt();

			List<Integer> path = new ArrayList<>(num);
			for (int j = 0; j < num; j++) {
				path.add(scan.nextInt());
			}

			Response response = check(path, graph, n);
			if (ResultEnum.DISTANCE_NOT_EXISTS.equals(response.result)) {
				System.out.printf("Path %d: NA (Not a TS cycle)\n", i);
			} else if (ResultEnum.NOT_CYCLE.equals(response.result)) {
				System.out.printf("Path %d: %d (Not a TS cycle)\n", i, response.dist);
			} else {
				if (ResultEnum.CYCLE.equals(response.result)) {
					System.out.printf("Path %d: %d (TS cycle)\n", i, response.dist);
				} else {
					System.out.printf("Path %d: %d (TS simple cycle)\n", i, response.dist);
				}
				if (response.dist < shortestDist) {
					shortestDist = response.dist;
					idx = i;
				}
			}
		}
		scan.close();

		System.out.printf("Shortest Dist(%d) = %d\n", idx, shortestDist);
	}

	private static Response check(List<Integer> path, int[][] graph, int n) {
		Response response = new Response();

		Set<Integer> set = new HashSet<>();
		for (int i = 0; i < path.size() - 1; i++) {
			int u = path.get(i);
			int v = path.get(i + 1);
			// 路径不连续
			if (graph[u][v] == 0) {
				response.result = ResultEnum.DISTANCE_NOT_EXISTS;
				return response;
			}
			response.dist += graph[u][v];
			set.add(u);
		}

		// 首尾城市编号不相同，或者没有走完全部的城市
		if (path.get(0) != path.get(path.size() - 1) || set.size() != n) {
			response.result = ResultEnum.NOT_CYCLE;
			return response;
		}

		if (set.size() + 1 != path.size()) {
			response.result = ResultEnum.CYCLE;
			return response;
		}

		response.result = ResultEnum.SIMPLE_CYCLE;
		return response;
	}

	static class Response {
		ResultEnum result;
		int dist;
	}

	enum ResultEnum {
		DISTANCE_NOT_EXISTS, NOT_CYCLE, CYCLE, SIMPLE_CYCLE;
	}
}