import type { WifiScanStatus } from '$lib/_fbs/open-shock/serialization/types/wifi-scan-status';
import type { WiFiNetwork, WiFiNetworkGroup } from './';

export type DeviceState = {
  wifiConnectedBSSID: string | null;
  wifiScanStatus: WifiScanStatus | null;
  wifiNetworks: Map<string, WiFiNetwork>;
  wifiNetworkGroups: Map<string, WiFiNetworkGroup>;
  gatewayPaired: boolean;
  rfTxPin: number | null;
};
