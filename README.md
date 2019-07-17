# MahalanobisEuclideanPR
This project discusses concentrates on pattern classification system. In this report, two classifiers have been discussed namely Minimum Distance classifier and Mahalanobis Distance classifier. Four popular real- valued datasets which consist of data from two classes are used to evaluate the performance of both the Mahalanobis distance classifier and the Minimum distance Classifier. The two classifiers are evaluated on the basis of Accuracy, Precision, Recall and F-measure. It is seen that the Mahalanobis distance classifier outperforms the Minimum distance Classifier in these five datasets.
Requirements:
LinuxOS
GNUPlot
DataSet Source -UCI ML Repository
It can be seen from the results that Mahalanobis classifier provides better result than minimum
distance classifier. This is because the Mahalanobis distance classifier uses the Covariance Matrix
which provides it an insight to the data distribution of the two classes. On the other hand, the Minimum
distance classifier considers the classes to be circular in shape(in case of bivariate distribution). Thus,
the Mahalanobis Distance Classifier is able to classify more properly. In the case of the EEG Eye
State dataset, it might happen that the Mahalanobis Distance was expecting a certain elliptical
distribution of the data in the two classes which might not have been true for this dataset and it may
turn out that the assumption of the Minimum Distance classifier, being that the data distribution is
circular in nature, was better. Thus, the Minimum distance classifier performed better.
