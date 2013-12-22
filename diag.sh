#! /bin/sh

loop_max=10
loopc=1
while [[ $loopc -gt 0 ]];do
echo "======start====="
diag_dci_client 539 0 8 0
diag_dci_client 1183 0 8 0
diag_dci_client 1863 0 8 0
diag_dci_client 67232 0 2 nv/item_files/modem/uim/uimdrv/hotswap_card_inserted_level
diag_dci_client 67353 0 11 nv/item_files/modem/uim/uimdrv/feature_support_hotswap
diag_dci_client 67330 0 8 nv/item_files/modem/uim/uimdrv/uim_features_status_list
diag_dci_client 70249 0 2 nv/item_files/modem/uim/uimdrv/max_null_proc_bytes
echo "======end====="
done