#ifndef CASHFLOWS_H
#define CASHFLOWS_H

#include <ctime>
#include <vector>

class CashFlow
{
public:
  struct tm paymentDate;
  double endingBalance;
  double grossInterest;
  double netInterest;
  double coupon;
  double scheduledPrincipal;
  double unscheduledPrincipal;
  double loss;
  double prepayPenalty;
};

class CashFlows
{
private:
  std::vector<CashFlow> periodicCashflows;
public:
  void prettyPrint();
  double yieldToMaturity(struct tm settleDate, double price);
  double weightedAverageLife(struct tm settleDate);
  friend class CashFlowEngine;
  template <typename PairContainer> // Assume std::map for now, use type_traits later
  static CashFlows aggregateCashFlows(PairContainer container)
  {
    CashFlows retCashFlows;
    for (auto &element : container)
    {
      // TODO: Actually aggregate the flows
      retCashFlows = element.second;
    }
    return retCashFlows;
  }
};

#endif