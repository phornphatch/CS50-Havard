# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000

def main():

    # Ensure correct usage
    if len(sys.argv) != 2: # the number of command-line arguments
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file (which will eventually be a list of teams)
    with open(sys.argv[1]) as file:
        file_reader = csv.DictReader(file)
        for team in file_reader:
            team["rating"] = int(team["rating"])  # specify rating to integer ปกติจะเอาเข้าเปน string หมด
            teams.append(team) # หมายถึง เขียน all teams

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    for i in range(N): # N is 1000
        winner = simulate_tournament(teams)
        if winner in counts:
            counts[winner] += 1
        else:
            counts[winner] = 1


    # Print each team's chances of winning, according to simulation
    # sort the teams in descending order of how many times they won simulations (according to counts)
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    # use simulate_round function, which accepts a list of teams and returns a list of winners
    # repeatedly sumulate rounds intil one team is left
    # return name of winning team
    while len(teams) > 1:
        teams = simulate_round(teams)
    return teams[0]["team"] # เข้าไปที่ first element เข้าไปหาชื่อ team


if __name__ == "__main__":
    main()
