using System;
using System.Diagnostics;

namespace Lab1P2 {
class Program {
    static int Main(string[] args)
    {
        try
        {
            Console.WriteLine("Process ID is: {0}", Process.GetCurrentProcess().Id);

            var psi = new ProcessStartInfo
            {
                FileName = "whoami",
                RedirectStandardOutput = true,
                RedirectStandardError = true,
                UseShellExecute = false,
                CreateNoWindow = true
            };

            using (var child = Process.Start(psi))
            {
                if (child == null)
                {
                    Console.Error.WriteLine("Failed to start child process");
                    return 1;
                }

                string stdout = child.StandardOutput.ReadToEnd();
                string stderr = child.StandardError.ReadToEnd();
                child.WaitForExit();

                if (!string.IsNullOrEmpty(stdout)) Console.Write(stdout);
                if (!string.IsNullOrEmpty(stderr)) Console.Error.Write(stderr);

                return child.ExitCode;
            }
        }
        catch (Exception e)
        {
            Console.Error.WriteLine(e.Message);
            return 1;
        }
    }
  }
}
