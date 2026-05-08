#define MAX_VAL 1000001

// Linked list node to store indices in prime buckets
typedef struct Node {
    int index;
    struct Node* next;
} Node;

int minJumps(int* nums, int numsSize) {
    if (numsSize <= 1) return 0;

    // 1. Sieve of Eratosthenes (Smallest Prime Factor)
    // We use a static array to handle the size efficiently
    static int spf[MAX_VAL];
    if (spf[2] == 0) { // Only compute once
        for (int i = 2; i < MAX_VAL; i++) spf[i] = i;
        for (int i = 2; i * i < MAX_VAL; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j < MAX_VAL; j += i)
                    if (spf[j] == j) spf[j] = i;
            }
        }
    }

    // 2. Build Prime Buckets (Adjacency List)
    // Maps each prime to a list of indices where nums[i] is a multiple of that prime
    Node** primeBuckets = (Node**)calloc(MAX_VAL, sizeof(Node*));
    for (int i = 0; i < numsSize; i++) {
        int temp = nums[i];
        while (temp > 1) {
            int p = spf[temp];
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->index = i;
            newNode->next = primeBuckets[p];
            primeBuckets[p] = newNode;
            // Remove all instances of this prime factor
            while (temp % p == 0) temp /= p;
        }
    }

    // 3. BFS Setup
    int* queue = (int*)malloc(sizeof(int) * numsSize);
    int* dist = (int*)malloc(sizeof(int) * numsSize);
    bool* visitedIdx = (bool*)calloc(numsSize, sizeof(bool));
    bool* visitedPrimes = (bool*)calloc(MAX_VAL, sizeof(bool));

    int head = 0, tail = 0;
    
    // Start BFS from index 0
    queue[tail++] = 0;
    visitedIdx[0] = true;
    dist[0] = 0;

    int result = -1;

    while (head < tail) {
        int curr = queue[head++];
        int currentDist = dist[curr];

        if (curr == numsSize - 1) {
            result = currentDist;
            break;
        }

        // --- Neighbor Move: Left and Right ---
        int moves[2] = {curr - 1, curr + 1};
        for (int i = 0; i < 2; i++) {
            int next = moves[i];
            if (next >= 0 && next < numsSize && !visitedIdx[next]) {
                visitedIdx[next] = true;
                dist[next] = currentDist + 1;
                queue[tail++] = next;
            }
        }

        // --- Teleportation: If nums[curr] is prime ---
        int val = nums[curr];
        if (val >= 2 && spf[val] == val) { // Check if prime
            if (!visitedPrimes[val]) {
                Node* it = primeBuckets[val];
                while (it) {
                    if (!visitedIdx[it->index]) {
                        visitedIdx[it->index] = true;
                        dist[it->index] = currentDist + 1;
                        queue[tail++] = it->index;
                    }
                    it = it->next;
                }
                visitedPrimes[val] = true; // Never process this prime bucket again
            }
        }
    }

    // 4. Cleanup
    for (int i = 0; i < MAX_VAL; i++) {
        Node* it = primeBuckets[i];
        while (it) {
            Node* toFree = it;
            it = it->next;
            free(toFree);
        }
    }
    free(primeBuckets);
    free(queue);
    free(dist);
    free(visitedIdx);
    free(visitedPrimes);

    return result;
}