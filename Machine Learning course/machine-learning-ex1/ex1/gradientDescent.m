function [theta, J_history] = gradientDescent(X, y, theta, alpha, num_iters)
%GRADIENTDESCENT Performs gradient descent to learn theta
%   theta = GRADIENTDESENT(X, y, theta, alpha, num_iters) updates theta by 
%   taking num_iters gradient steps with learning rate alpha

% Initialize some useful values
m = length(y); % number of training examples
J_history = zeros(num_iters, 1);
n = size(X, 2);
tmp = theta;

for iter = 1:num_iters
    for j = 1:n
        current = theta(j,:);
        sum = 0;


        for i = 1:m
            A = X(i,:);
            sum = sum + (theta' * A' - y(i,:)) * X(i,j);
        endfor

        sum = sum / m * alpha;

        current = current - sum;
        tmp(j,:) = current;
    endfor

    theta = tmp;

    % ====================== YOUR CODE HERE ======================
    % Instructions: Perform a single gradient step on the parameter vector
    %               theta. 
    %
    % Hint: While debugging, it can be useful to print out the values
    %       of the cost function (computeCost) and gradient here.
    %







    % ============================================================

    % Save the cost J in every iteration    
    J_history(iter) = computeCost(X, y, theta);

end

end
