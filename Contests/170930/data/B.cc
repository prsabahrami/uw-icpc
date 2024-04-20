#include <bits/stdc++.h>

using namespace std;

namespace {

#define VERA(i, a, b)for(auto i=(ll)(a);i<(ll)(b);++i)
#define ANDY(i, a, b)for(auto i=(ll)(a);i>(ll)(b);--i)

typedef long long ll;
typedef long double dd;

struct Card {
  int rank, suit;

  bool operator<(const Card& c) const {
    return tie(rank, suit) < tie(c.rank, c.suit);
  }

  bool operator!=(const Card& c) const {
    return tie(rank, suit) != tie(c.rank, c.suit);
  }

  void Read() {
    cin >> rank >> suit;
  }
};

struct Hand {
  vector<Card> cards;
  int cnt_rank[25], cnt_suit[4];

  void Init() {
    sort(cards.begin(), cards.end());
    memset(cnt_rank, 0, sizeof(cnt_rank));
    memset(cnt_suit, 0, sizeof(cnt_suit));
    for (const auto& card : cards) {
      ++cnt_rank[card.rank];
      ++cnt_suit[card.suit];
    }
    sort(cnt_rank, cnt_rank + 25);
    reverse(cnt_rank, cnt_rank + 25);
    sort(cnt_suit, cnt_suit + 4);
    reverse(cnt_suit, cnt_suit + 4);
  }

  bool Flush() const {
    return cnt_suit[0] == 5;
  }

  bool Straight() const {
    VERA(i, 0, cards.size() - 1) {
      if (cards[i].rank + 1 != cards[i + 1].rank)
        return false;
    }
    return true;
  }

  bool StraightFlush() const {
    return Flush() && Straight();
  }

  bool TwoPair() const {
    return cnt_rank[0] == 2 && cnt_rank[1] == 2;
  }

  bool Pair() const {
    return cnt_rank[0] == 2;
  }

  bool FullHouse() const {
    return cnt_rank[0] == 3 && cnt_rank[1] == 2;
  }

  bool ThreeOfAKind() const {
    return cnt_rank[0] == 3;
  }

  bool FourOfAKind() const {
    return cnt_rank[0] == 4;
  }
};

void Solve(ll test_num) {
  (void) test_num;
  int A, B;
  cin >> A >> B;
  Card c1, c2;
  c1.Read();
  c2.Read();
  vector<Card> rem;
  VERA(r, 0, A) {
    VERA(s, 0, B) {
      Card c{r, s};
      if (c != c1 && c != c2) {
        rem.push_back(c);
      }
    }
  }
  vector<int> res(9, 0);
  VERA(i, 0, rem.size()) {
    VERA(j, i + 1, rem.size()) {
      VERA(k, j + 1, rem.size()) {
        Hand hand{{rem[i], rem[j], rem[k], c1, c2}};
        hand.Init();
        if (hand.StraightFlush())
          ++res[0];
        else if (hand.FourOfAKind())
          ++res[1];
        else if (hand.FullHouse())
          ++res[2];
        else if (hand.Flush())
          ++res[3];
        else if (hand.Straight())
          ++res[4];
        else if (hand.ThreeOfAKind())
          ++res[5];
        else if (hand.TwoPair())
          ++res[6];
        else if (hand.Pair())
          ++res[7];
        else
          ++res[8];
      }
    }
  }
  VERA(i, 0, 9) cout << res[i] << " \n"[i == 8];
}

void Init() {
}

}

int main() {
#ifdef AZN
  const auto start_time = chrono::system_clock::now();
  freopen("../../input.txt", "r", stdin);
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  srand(1223);
  Init();
  ll tests = 1;
//  cin >> tests;
  VERA(test, 1, tests + 1) {
    Solve(test);
  }
#ifdef AZN
  cerr << "Took: " << ((chrono::system_clock::now() - start_time).count() / 1e9) << " s" << endl;
#endif
  return 0;
}
