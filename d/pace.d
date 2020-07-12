import std.stdio;
import std.conv;

void main() {

    writeln("\n=======================");
    writeln("Running pace calculator");
    writeln("=======================\n");

    int distance;
    write("Distance in metres >> ");
    try {
        readf("%d\n", &distance);
    }
    catch (Exception e) {
        writeln("Invalid distance!");
        return;
    }

    int minutes;
    int seconds;
    write("Time in minutes:seconds >> ");
    try {
        readf("%d:%d\n", &minutes, &seconds);
    }
    catch (Exception e) {
        writeln("Invalid time!");
        return;
    }

    int totalseconds = minutes*60 + seconds;
    double km = distance/1000.0;

    int secondsPerKm = roundTo!int(totalseconds/km);

    int paceMins = secondsPerKm / 60;
    int paceSecs = secondsPerKm % 60;

    writeln("\nYour time per km is ", paceMins, ":", paceSecs, "\n");

}
