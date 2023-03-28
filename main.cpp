#include <iostream>
#include <vector>
#include <limits>

using namespace std;

using vi = vector<int>;

class solution {
public:
	solution() = default;

	virtual ~solution() = default;

private:
	int n_{};
	vi dat_{};
	vi ops_{};
	int mx_{};
	int mn_{};

public:
	void input() {
		cin >> n_;

		dat_ = vi(n_);
		for (auto i = 0; i < n_; ++i) {
			cin >> dat_[i];
		}

		ops_ = vi(4);
		for (auto i = 0; i < 4; ++i) {
			cin >> ops_[i];
		}
	}

	void solve() {
		mx_ = numeric_limits<int>::min();
		mn_ = numeric_limits<int>::max();

		solvePart(dat_[0], 1);
	}

	void output() const noexcept {
		cout << mx_ << '\n' << mn_;
	}

private:
	void solvePart(int now, int ct) {
		if (ct == n_) {
			if (mx_ < now) {
				mx_ = now;
			}

			if (now < mn_) {
				mn_ = now;
			}

			return;
		}

		for (auto i = 0; i < 4; ++i) {
			if (0 == ops_[i]) {
				continue;
			}

			--ops_[i];
			if (0 == i) {
				solvePart(now + dat_[ct], ct + 1);
			}
			else if (1 == i) {
				solvePart(now - dat_[ct], ct + 1);
			}
			else if (2 == i) {
				solvePart(now * dat_[ct], ct + 1);
			}
			else if (3 == i) {
				solvePart(now / dat_[ct], ct + 1);
			}
			++ops_[i];
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	auto s = solution{};
	s.input();
	s.solve();
	s.output();

	return 0;
}