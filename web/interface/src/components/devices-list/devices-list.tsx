import styles from './devices-list.module.scss';
import classNames from 'classnames';
import { DevicePreview } from '../device-preview/device-preview';

export interface DevicesListProps {
    className?: string;
}

/**
 * This component was created using Codux's Default new component template.
 * To create custom component templates, see https://help.codux.com/kb/en/article/kb16522
 */
export const DevicesList = ({ className }: DevicesListProps) => {
    return (
        <div className={classNames(styles.root, className)}>
            <h1 className={styles.title}>Connected devices</h1>
            <div className={styles.grid}>
                {}
            </div>
        </div>
    );
};
