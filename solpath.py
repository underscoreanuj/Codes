from collections import deque


def get_best_path(grid_map):
    rows = len(grid_map)
    cols = len(grid_map[0])

    class Node:
        def __init__(self, x, y, can_break):
            self.x = x
            self.y = y
            self.can_break = can_break              # a boolean to specify whether or not we can break a wall (should a path be traced from this node)

        def __hash__(self):
            return self.x ^ self.y

        def __eq__(self, other):
            return self.x == other.x and self.y == other.y and self.can_break == other.can_break

        def get_neighbour_nodes(self):
            neighbours = []

            if self.x > 0:          # can go up
                # can go to next node (no wall)
                if grid_map[self.x-1][self.y] == 0:
                    neighbours.append(Node(self.x-1, self.y, self.can_break))
                elif self.can_break:                            # (wall present and) can break a wall
                    neighbours.append(Node(self.x-1, self.y, False))

            if self.x < rows-1:          # can go down
                # can go to next node (no wall)
                if grid_map[self.x+1][self.y] == 0:
                    neighbours.append(Node(self.x+1, self.y, self.can_break))
                elif self.can_break:                            # (wall present and) can break a wall
                    neighbours.append(Node(self.x+1, self.y, False))

            if self.y > 0:          # can go left
                # can go to next node (no wall)
                if grid_map[self.x][self.y-1] == 0:
                    neighbours.append(Node(self.x, self.y-1, self.can_break))
                elif self.can_break:                            # (wall present and) can break a wall
                    neighbours.append(Node(self.x, self.y-1, False))

            if self.y < cols-1:          # can go right
                # can go to next node (no wall)
                if grid_map[self.x][self.y+1] == 0:
                    neighbours.append(Node(self.x, self.y+1, self.can_break))
                elif self.can_break:                            # (wall present and) can break a wall
                    neighbours.append(Node(self.x, self.y+1, False))

            return neighbours

    # start from top-left
    start = Node(0, 0, True)
    queue = deque([start])
    distances = {start: 1}

    # perform breadth-first-traversal
    while len(queue):
        cur_node = queue.popleft()

        # if we reached the escape pod
        if cur_node.x == rows-1 and cur_node.y == cols-1:
            return distances[cur_node]

        # iterate over the possible neighbours from the current node
        for next_node in cur_node.get_neighbour_nodes():
            if next_node not in distances.keys():
                distances[next_node] = distances[cur_node] + 1
                queue.append(next_node)

    # no possible path found
    return -1


res = get_best_path([[0, 1, 1, 0], [0, 0, 0, 1], [1, 1, 0, 0], [1, 1, 1, 0]])
print(res)
