#include "node.h"

bool DateComparisonNode::Evaluate(const Date& date,
          const string& event) const {
    if (cmp_ == Comparison::Less) {
        return date < date_;
    } else if (cmp_ == Comparison::LessOrEqual) {
        return date <= date_;
    } else if (cmp_ == Comparison::Greater) {
        return date > date_;
    } else if (cmp_ == Comparison::GreaterOrEqual) {
        return date >= date_;
    } else if (cmp_ == Comparison::Equal) {
        return date == date_;
    } else if (cmp_ == Comparison::NotEqual) {
        return date != date_;
    }

    /// for compilability, always ignored
    return event.empty();
}



bool EventComparisonNode::Evaluate(const Date& date,
          const string& event) const {
    if (cmp_ == Comparison::Less) {
        return event < value_;
    } else if (cmp_ == Comparison::LessOrEqual) {
        return event <= value_;
    } else if (cmp_ == Comparison::Greater) {
        return event > value_;
    } else if (cmp_ == Comparison::GreaterOrEqual) {
        return event >= value_;
    } else if (cmp_ == Comparison::Equal) {
        return event == value_;
    } else if (cmp_ == Comparison::NotEqual) {
        return event != value_;
    }

    /// for compilability, always ignored
    return bool(date.GetYear());
}



bool LogicalOperationNode::Evaluate(const Date& date,
          const string& event) const {
    if (op_ == LogicalOperation::And) {
        return left_->Evaluate(date, event) && right_->Evaluate(date, event);
    } else if (op_ == LogicalOperation::Or) {
        return left_->Evaluate(date, event) || right_->Evaluate(date, event);
    }

    /// for compilability
    return false;
}
