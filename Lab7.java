import java.util.Scanner;

public class deadlockprev {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        int n = scanner.nextInt();

        System.out.print("Enter number of resource types: ");
        int r = scanner.nextInt();

        int[][] allocation = new int[n][r];
        int[][] max = new int[n][r];
        int[] available = new int[r];

        System.out.println("Enter the allocation matrix (" + n + "x" + r + "):");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < r; j++) {
                allocation[i][j] = scanner.nextInt();
            }
        }

        System.out.println("Enter the maximum demand matrix (" + n + "x" + r + "):");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < r; j++) {
                max[i][j] = scanner.nextInt();
            }
        }

        System.out.println("Enter available resources (" + r + "):");
        for (int j = 0; j < r; j++) {
            available[j] = scanner.nextInt();
        }

        // calculate need matrix goes here
        int[][] need = new int[n][r];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < r; j++) {
                need[i][j] = max[i][j] - allocation[i][j];
            }
        }

        // safety algorithm here
        boolean[] finished = new boolean[n];
        int[] work = new int[r];
        System.arraycopy(available, 0, work, 0, r);

        boolean progress = true;
        while (progress) {
            progress = false;
            for (int i = 0; i < n; i++) {
                if (!finished[i]) {
                    boolean canAllocate = true;
                    for (int j = 0; j < r; j++) {
                        if (need[i][j] > work[j]) {
                            canAllocate = false;
                            break;
                        }
                    }
                    if (canAllocate) {
                        // pretend to allocate and release
                        for (int j = 0; j < r; j++) {
                            work[j] += allocation[i][j];
                        }
                        finished[i] = true;
                        progress = true;
                    }
                }
            }
        }

        boolean safe = true;
        for (int i = 0; i < n; i++) {
            if (!finished[i]) {
                safe = false;
                break;
            }
        }

        if (safe) {
            System.out.println("The system is in a safe state, Deadlock is unlikely to happen.");
        } else {
            System.out.println("The system is NOT in a safe state, Deadlock is possible to occur.");
        }

        scanner.close();
    }
}
