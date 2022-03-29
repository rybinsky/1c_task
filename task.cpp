#include <iostream>
#include <vector>
#include <climits>
#define INF INT_MAX
#define maxT 1440

using namespace std;

// ребро
struct Edge {
	int tBegin; // момент открытия ребра
	int tEnd; // момент закрытия ребра
	int src; // откдуда
	int dst; // куда
};

// поиск путей
void Searching(const int nStations, const vector<Edge>& edges, vector<int>& minTime, vector<pair<int, int>>& minTstations) {
	for (int i = 1; i < nStations; i++) {
		for (const Edge& edge : edges) {
			if (edge.tBegin >= minTime[edge.src]) {
				if (edge.tEnd < minTime[edge.dst]) {
					minTime[edge.dst] = edge.tEnd;
					minTstations[edge.dst].first = edge.src; // добавим станцию в маршрут
					minTstations[edge.dst].second = edge.tBegin - minTime[edge.src]; // сколько ждать на этой станции
				}
			}
		}
	}
}

void GenTimeTable(const int countTrains, vector<Edge>& edges) {

	for (int i = 0; i < countTrains; i++) {

		int countStations, rangeT, startTime; // число станций на пути и интервал выхода из депо, когда выйдет впервые
		cin >> countStations >> rangeT >> startTime;
		int countTrains = (maxT - startTime) / rangeT; // сколько всего выйдет поездов за оставшиеся сутки из депо
		int time = startTime;
		int prevSt, prev_to_curT; 
		cin >> prevSt; // вводим первую станцию на ветке

		for (int j = 1; j < countStations; j++) {
			int curSt;
			cin >> prev_to_curT >> curSt; // вводим время между предыдущей и текущей станциями и номер текущей станции
			for (int k = 0; k < countTrains; k++) { // вводим все рейсы этого поезда за сутки между этими станциями
				edges.push_back({ time + k * rangeT, time + prev_to_curT + k * rangeT, prevSt, curSt });
			}
			time += prev_to_curT;
			prevSt = curSt; 
		}
	}
}

int main() {
	
	int nStations, countTrains; // число станций и поездов
	cin >> nStations >>  countTrains;
	vector<Edge> edges;

	GenTimeTable(countTrains, edges); // генерация всего расписания на день

	// обработка запросов
	int nowTime, start, end; // время текущее, откуда выезжаем и куда хотим
	while (1) {

		cin >> start >> end >> nowTime;

		vector<int> minTime(1 + nStations, INF); // массив, где будем хранить минимальное время, 
											     // во сколько прибудем на соответствующую станцию
		vector<pair<int, int>> minTstations(1 + nStations, { -1, -1 });

		minTime[start] = nowTime; // до станции где мы сейчас мы доедем в текущий момент времени

		Searching(nStations, edges, minTime, minTstations); // вычисление времен и самого маршрута

		if (minTime[end] == INF) {
			cout << "You can't get to the station " << end << " from the station " << start << " by metro" << endl;
			continue;
		}
		else {
			cout << "Minimal time: " << minTime[end] - nowTime << endl;
		}
		
		// восстановим маршрут
		cout << "Your route: " << endl;
		vector<pair<int, int>> route;
		route.push_back({ end, 0 });
		int wait; // ожидание на конкретной станции
		while (end != start) {
			wait = minTstations[end].second;
			end = minTstations[end].first;
			route.push_back({ end, wait });
		}
		reverse(route.begin(), route.end());
		
		// выведем маршрут
		// cout << route[0].first << ", get on a train!" << endl;
		for (int i = 0; i < route.size() - 1; i++) {
			if (route[i].second == 0) {
				cout << route[i].first << ", keep going" << endl;
			}
			else {
				cout << route[i].first << ", please, wait " << route[i].second << " minutes" << endl;
			}
		}
		cout << route.back().first << ", coming out!" << endl;
	}
	return 0;
}