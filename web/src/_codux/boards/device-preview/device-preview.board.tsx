import { createBoard } from '@wixc3/react-board';
import { DevicePreview } from '../../../components/device-preview/device-preview';

export default createBoard({
    name: 'DevicePreview',
    Board: () => <DevicePreview />,
    environmentProps: {
        canvasHeight: 259,
    },
});
