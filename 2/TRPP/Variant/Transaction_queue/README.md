# Transaction_queue
## This project is a financial transaction processing system using a pre-trained machine learning model. The main tasks of the project include processing provider and transaction data, dynamically updating provider limits, generating features for the model, predicting the success of transaction processing, and generating provider chains for payment fulfillment.

## Key steps:
### Data loading and preprocessing:
Loading provider, transaction and exchange rate data from CSV files.
Provider data preprocessing: sorting and updating limits (LIMIT_MIN, LIMIT_MAX) based on time.

### Traits generation:
Extraction and generation of traits based on transaction and provider data.
Ability to reuse previously generated traits or regenerate them.

### Trained model:
Use of a pre-trained model (trained_model.joblib) to predict the success of transaction processing.

### Transaction Processing:
Predicting the probability of successful transaction processing for each provider.
Formation of a chain of providers through which a payment can be made.
Dynamic updating of provider limits during transaction processing.

### Results:
Formation of a final file with results (results.csv), including information about the status of payments and provider chains.
