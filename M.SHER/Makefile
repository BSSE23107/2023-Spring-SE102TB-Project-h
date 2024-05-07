all: ./a.out

compRun:
	g++ -std=c++11 main.cpp Person.cpp Candidate.cpp Verification.cpp Voter.cpp Party.cpp ElectionMachine.cpp Result.cpp PersonalDetails.cpp Login.cpp -o r.out

compTest:
	g++ -std=c++11 main.cpp Person.cpp Candidate.cpp Verification.cpp Voter.cpp Party.cpp ElectionMachine.cpp Result.cpp PersonalDetails.cpp Login.cpp -o r.out


test: clean compTest; ./a.out

run: clean compRun; ./r.out

clean:
	rm -f *.out
