function plotData(X, y)
%PLOTDATA Plots the data points X and y into a new figure 
%   PLOTDATA(x,y) plots the data points with + for the positive examples
%   and o for the negative examples. X is assumed to be a Mx2 matrix.

% Create New Figure
figure; hold on;

n = length(y);
z1 = [];
z2 = [];

for i = 1:n
    if y(i) == 0
        z1 = [z1; X(i, :)];
    else
        z2 = [z2; X(i, :)];
    end;
end;

plot(z1(:, 1), z1(:, 2), 'ok', 'markerfacecolor', 'y', 'markersize', 7);
plot(z2(:, 1), z2(:, 2), '+k', 'linewidth', 2, 'markersize', 7);

% ====================== YOUR CODE HERE ======================
% Instructions: Plot the positive and negative examples on a
%               2D plot, using the option 'k+' for the positive
%               examples and 'ko' for the negative examples.
%









% =========================================================================



hold off;

end
