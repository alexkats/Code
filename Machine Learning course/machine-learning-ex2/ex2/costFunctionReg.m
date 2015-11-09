function [J, grad] = costFunctionReg(theta, X, y, lambda)
%COSTFUNCTIONREG Compute cost and gradient for logistic regression with regularization
%   J = COSTFUNCTIONREG(theta, X, y, lambda) computes the cost of using
%   theta as the parameter for regularized logistic regression and the
%   gradient of the cost w.r.t. to the parameters. 

% Initialize some useful values
m = length(y); % number of training examples
n = size(X, 2);

% You need to return the following variables correctly 
J = 0;
tmp = [0; theta(2:n, :)];

J = log(sigmoid(theta' * X'))' .* y + log(1 - sigmoid(theta' * X'))' .* (1 - y);
J = sum(J);
J = -J / m;
JReg = tmp .^ 2;
JReg = sum(JReg);
JReg = JReg * lambda / 2 / m;
J = J + JReg;

grad = zeros(size(theta));

for i = 1:n
    grad(i) = sum((sigmoid(theta' * X')' - y) .* X(:,i)) / m + lambda * tmp(i) / m;;
end;

% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost of a particular choice of theta.
%               You should set J to the cost.
%               Compute the partial derivatives and set grad to the partial
%               derivatives of the cost w.r.t. each parameter in theta






% =============================================================

end
