package com.alex.calculator;

import android.util.Log;

public class Evaluation {

    private interface Expression {
        double evaluate();
    }

    public class Number implements Expression {
        private final double value;

        public Number(double value) {
            this.value = value;
        }

        public double evaluate() {
            return value;
        }
    }

    protected abstract class Operation implements Expression {
        protected Expression first, second;

        protected Operation(Expression first) {
            this.first = first;
        }

        protected Operation(Expression first, Expression second) {
            this.first = first;
            this.second = second;
        }
    }

    public class Add extends Operation {
        public Add(Expression first, Expression second) {
            super(first, second);
        }

        public double evaluate() {
            return first.evaluate() + second.evaluate();
        }
    }

    public class Subtract extends Operation {
        public Subtract(Expression first, Expression second) {
            super(first, second);
        }

        public double evaluate() {
            return first.evaluate() - second.evaluate();
        }
    }

    public class Multiply extends Operation {
        public Multiply(Expression first, Expression second) {
            super(first, second);
        }

        public double evaluate() {
            return first.evaluate() * second.evaluate();
        }
    }

    public class Divide extends Operation {
        public Divide(Expression first, Expression second) {
            super(first, second);
        }

        public double evaluate() {
            return first.evaluate() / second.evaluate();
        }
    }

    public class UnaryMinus extends Operation {
        public UnaryMinus(Expression first) {
            super(first);
        }

        public double evaluate() {
            return -first.evaluate();
        }
    }

    private String s;
    private int index;

    private Expression operand() {
        if (s.charAt(index) == '-') {
            index++;
            return new UnaryMinus(brackets());
        }

        Expression ans;
        double value = 0;

        while (Character.isDigit(s.charAt(index))) {
            value = value * 10 + (double) (s.charAt(index) - '0');
            index++;

            if (s.length() == index) {
                break;
            }
        }

        if (s.length() > index && s.charAt(index) == '.') {
            index++;
        }

        long other = 0;
        int q = 0;

        while (s.length() > index && Character.isDigit(s.charAt(index))) {
            other = other * 10 + (int) (s.charAt(index) - '0');
            index++;
            q++;
        }

        long div = 1;

        for (int i = 0; i < q; i++) {
            div *= 10;
        }

        value = value + (double) other / (double) div;
        ans = new Number(value);
        return ans;
    }

    private Expression brackets() {
        Expression ans;

        if (s.charAt(index) == '(') {
            index++;
            ans = expression();
            index++;
        } else {
            ans = operand();
        }

        return ans;
    }

    private Expression expression() {
        Expression ans = prior();

        while (s.length() > index) {
            switch (s.charAt(index)) {
                case '+':
                    index++;
                    ans = new Add(ans, prior());
                    break;
                case '-':
                    index++;
                    ans = new Subtract(ans, prior());
                    break;
                default:
                    return ans;
            }
        }

        return ans;
    }

    private Expression prior() {
        Expression ans = brackets();

        while (s.length() > index) {
            switch (s.charAt(index)) {
                case '*':
                    index++;
                    ans = new Multiply(ans, brackets());
                    break;
                case '/':
                    index++;
                    ans = new Divide(ans, brackets());
                    break;
                default:
                    return ans;
            }
        }

        return ans;
    }

    public double result(String input) {
        s = input;
        index = 0;
        return expression().evaluate();
    }
}