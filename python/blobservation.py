class Blobservation:
    #your code goes here. you can do it!
    def __init__(self, h, w = None):
        self.height = h
        self.width = w or h
        self.blobs = []
        
    def populate(self,  blobs):
        # Initial checks
        if(len(blobs) < 2):
            return blobs
        if any(b['x'] >= self.height or b['y'] >= self.width or b['x'] < 0 or b['y'] < 0 or b['size'] <= 0 or type(b['x']) is not int or type(b['y']) is not int or type(b['size']) is not int for b in blobs):
            raise ValueError("List contains invalid values !")
        # Add new blobs to blobs property
        for b in blobs:
            self.blobs.append([b['x'], b['y'], b['size']])
            if len(self.blobs) > 1:
                # Check for blobs on the same position for merging
                for b in self.blobs[:-1]:
                    if (b[0] == self.blobs[-1][0] and b[1] == self.blobs[-1][1]):
                        b[2] += self.blobs[-1][2]
                        self.blobs.pop(-1)        
                        break
        return self.blobs
    
    def print_state(self):
        if(len(self.blobs) > 1):
            return sorted([b for b in self.blobs], key = lambda l: (l[0], l[1]) )
        else:
            return self.blobs
        
    def move(self, n = 1):  
        # Initial checks
        if n < 1 or type(n) != int:
            raise ValueError("Invalid value !")
        if len(self.blobs) < 2:
            return self.blobs  
        # Used lambdas
        norm = lambda n: 1 if n > 0 else -1 if n < 0 else 0 
        clockwise = lambda x, y : x/((x**2 + y**2 + 1)**0.5)-1 if y < 0 else -x/((x**2 + y**2 + 1)**0.5)+1
        dist = lambda x, y, x1, y1: max([abs(x - x1), abs(y - y1)])        
        # Initial containers
        self.blobs = self.print_state()
        new_blobs = ['stuff','to_fill']
        distances = []   
        # Main loop
        while n > 0 and len(new_blobs) > 1:
            new_blobs = []
            for blob in self.blobs:
                targets = []    
                # Calculate distances from each blob for each blob (didn't have any better ideas)
                distances = [[dist(blob[0], blob[1], b[0], b[1]), b[0], b[1], b[2]] for b in self.blobs if blob[2] > b[2] and blob != b]   
                # Different scenarios
                if len(distances) == 1:
                    new_blobs.append([blob[0] + norm(distances[0][1] - blob[0]), blob[1] + norm(distances[0][2] - blob[1]), blob[2]])
                # If multiple targets sort according to: 1.distance, 2.size
                elif len(distances) > 1:
                    targets = sorted(distances, key = lambda c: (c[0], -c[3]))
                    # If multiple targets of same distance and size, sort clockwise
                    if targets[0][3] == targets[1][3]:
                        target = sorted(distances, key = lambda c: (-c[0], c[3], clockwise(norm(c[1]-blob[0]), norm(c[2]-blob[1]))), reverse=True)[0]
                    else:
                        target = targets[0]
                    # Calculate new blob coordinates according to chosen target
                    new_blobs.append([blob[0] + norm(target[1] - blob[0]), blob[1] + norm(target[2] - blob[1]), blob[2]])
                # If no target smaller than itself found do nothing
                elif not distances:
                    new_blobs.append([blob[0], blob[1], blob[2]])
                # Check if blob merging occured
                if len(new_blobs) > 1:
                    for b in new_blobs[:-1]:
                        if (b[0] == new_blobs[-1][0] and b[1] == new_blobs[-1][1]):
                            b[2] += new_blobs[-1][2]
                            new_blobs.pop(-1)        
                            break
            self.blobs = new_blobs
            n = n -1
        return self.blobs