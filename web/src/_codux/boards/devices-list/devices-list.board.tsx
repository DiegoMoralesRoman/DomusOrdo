import { createBoard } from '@wixc3/react-board';
import { DevicesList } from '../../../components/devices-list/devices-list';

export default createBoard({
    name: 'DevicesList',
    Board: () => <DevicesList />,
    environmentProps: {
        canvasWidth: 873,
        windowWidth: 1024,
        canvasHeight: 766,
    },
});
