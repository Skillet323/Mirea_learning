from collections import deque

def script(check, x, y):
    lvl = check("level")
    

    if lvl == 1:
        if check("gold", x, y):
            return "take"
        elif check("gold", x, y+1) == 0:
            return "right"
        elif check("gold", x+1, y) == 0:
            return "down"
        return "right"

    if lvl == 2:
        if check("gold", x, y):
            return "take"
        if check("gold", x, y+1):
            return "down"
        if check("wall", x, y-1):
            return "right"
        if check("gold", x+1, y):
            return "right"
        if check("gold", x+2, y):
            return "right"
        return "up"

    if lvl == 3:
        if check("gold", x, y):
            return "take"
        if check("gold", x+3, y):
            return "right"
        if (check("gold", x, y+1) or check("gold", x, y+2) or check("gold", x, y+3)):
            return "down"
        if (check("gold", x+2, y+8) or check("gold", x+5, y+6)):
            return "left"
        if ((check("gold", x+3, y+8) or check("gold", x+3, y+7) or check("gold", x+6, y+6))
            and not check("wall", x, y-1)):
            return "down"
        if ((check("gold", x-3, y+6) or check("gold", x-3, y+5) or check("gold", x-3, y+4))
            and not check("wall", x, y-1)):
            return "down"
        if ((check("gold", x-4, y+6) or check("gold", x-3, y+3) or check("gold", x-2, y+3)
             or check("gold", x-1, y+3))
            and check("wall", x, y+1) and not check("wall", x-1, y)):
            return "left"
        if check("wall", x-1, y+2) and not check("wall", x-1, y):
            return "left"
        if check("wall", x+1, y) and not check("wall", x, y+1):
            return "down"
        if check("wall", x-1, y+1) and not check("wall", x-1, y):
            return "left"
        if check("wall", x+1, y-1) and not check("wall", x+1, y):
            return "right"
        if not check("wall", x+1, y) and not check("wall", x, y-1):
            return "up"
        if check("wall", x-1, y-1) and not check("wall", x, y-1):
            return "up"
        if check("wall", x+1, y):
            return "down"
        return "right"
    
    if lvl == 4 or lvl == 5:

        if check("gold", x, y) > 0:
            return "take"
        

        if lvl == 4:
            width = 28
            height = 25
        elif lvl == 5:
            width = 17
            height = 17
        

        queue = deque([(x, y)])
        parent = {(x, y): None}
        found = False
        target = None
        
        while queue and not found:
            current = queue.popleft()
            if check("gold", current[0], current[1]) > 0:
                found = True
                target = current
                break
            for dx, dy in [(-1, 0), (1, 0), (0, -1), (0, 1)]: 
                nx = current[0] + dx
                ny = current[1] + dy
                if (0 <= nx < width and 0 <= ny < height and
                    not check("wall", nx, ny) and
                    not check("player", nx, ny) and
                    (nx, ny) not in parent):
                    parent[(nx, ny)] = current
                    queue.append((nx, ny))
        
        if found:
            path = []
            current = target
            while current is not None:
                path.append(current)
                current = parent[current]
            path.reverse()
            next_pos = path[1] 
            dx = next_pos[0] - x
            dy = next_pos[1] - y
            if dx == 1:
                return "right"
            elif dx == -1:
                return "left"
            elif dy == 1:
                return "down"
            elif dy == -1:
                return "up"
        else:
            return "pass"

    
    return "pass"
