import sys
import math

def Common_circle(p, q, r1, u, v, r2):
    d = math.sqrt((u - p)**2 + (v - q)**2)
    if d >= r1 + r2:
        return 0.0
    elif d <= abs(r1 - r2):
        return math.pi * min(r1, r2)**2
    else:
        angle1 = math.acos((d**2 + r1**2 - r2**2) / (2 * d * r1))
        angle2 = math.acos((d**2 + r2**2 - r1**2) / (2 * d * r2))
        triangle_area = 0.5 * math.sqrt((-d + r1 + r2) * (d + r1 - r2) * (d - r1 + r2) * (d + r1 + r2))
        return r1**2 * angle1 + r2**2 * angle2 - triangle_area

def solve():
    input = sys.stdin.readline
    N = int(input())
    
    stations = []
    max_radius = 0
    for _ in range(N):
        i, x, y, d = map(int, input().split())
        stations.append({'id': i, 'x': x, 'y': y, 'r': d})
        if d > max_radius:
            max_radius = d

    if max_radius == 0:
        return

    cell_size = 2 * max_radius
    grid = {}

    for i, s in enumerate(stations):
        gx = s['x'] // cell_size
        gy = s['y'] // cell_size
        if (gx, gy) not in grid:
            grid[(gx, gy)] = []
        grid[(gx, gy)].append(i)

    max_area = -1.0
    best_pair = (float('inf'), float('inf'))
    checked_pairs = set()

    for (gx, gy), cell_stations in grid.items():
        for dx in range(-1, 2):
            for dy in range(-1, 2):
                neighbor_cell = (gx + dx, gy + dy)
                if neighbor_cell in grid:
                    neighbor_stations = grid[neighbor_cell]
                    
                    for idx1 in cell_stations:
                        for idx2 in neighbor_stations:
                            if idx1 == idx2:
                                continue

                            current_pair = tuple(sorted((stations[idx1]['id'], stations[idx2]['id'])))

                            if current_pair in checked_pairs:
                                continue
                            checked_pairs.add(current_pair)

                            s1 = stations[idx1]
                            s2 = stations[idx2]

                            area = Common_circle(s1['x'], s1['y'], s1['r'], s2['x'], s2['y'], s2['r'])
                            truncated_area = int(area * 1000) / 1000.0
                            
                            if truncated_area > max_area:
                                max_area = truncated_area
                                best_pair = current_pair
                            elif truncated_area == max_area:
                                if current_pair < best_pair:
                                    best_pair = current_pair

    if best_pair[0] != float('inf'):
        print(best_pair[0], best_pair[1])

if __name__ == "__main__":
    solve()